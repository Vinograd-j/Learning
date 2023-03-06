#include <iostream>
#include <fstream>

typedef struct Vehicle {

private:
    std::string mark;
    size_t yearOfManufacture;
    size_t engineCapacity;
    size_t fuelConsumption;

public:

    Vehicle() = default;

    Vehicle(std::string mark, size_t yearOfManufacture, size_t engineCapacity, size_t fuelConsumption) : mark(mark), yearOfManufacture(yearOfManufacture), engineCapacity(engineCapacity), fuelConsumption(fuelConsumption) {}

    std::string GetMark() const {
        return this->mark;
    }

    size_t GetYearOfManufacture() const {
        return this->yearOfManufacture;
    }

    size_t GetEngineCapacity() const {
        return this->engineCapacity;
    }

    size_t GetFuelConsumption() const {
        return this->fuelConsumption;
    }

} Vehicle;

void readFromFile(Vehicle*& vehicles, size_t& size, const std::string& fileName);
void saveToFile(const Vehicle* vehicles, size_t size, const std::string& fileName);
void testReadFromFile();
void testSaveToFile();
void writeBytes(std::ofstream& out, size_t value, size_t size);


void maasdsdgfg5rr5t345324dfgxcg43win() {

    int a;
    std::cin >> a;

    std::cout <<  NAN;



   // testSaveToFile();
   // testReadFromFile();
}

void testSaveToFile() {

    Vehicle vehicles[] = {

        {
            "dasd",
            13,
            24,
            56
        },
                {
            "dasdasdasdasdasd",
            13123,
            21324,
            53126
        },
                {
            "asdasda",
            123213,
            21234,
            51231236
        },
    };

    saveToFile(vehicles, sizeof(vehicles) / sizeof(vehicles[0]), "Vehicles.txt");
}

void testReadFromFile() {

    Vehicle* vehs;
    size_t size = 0;

    readFromFile(vehs, size, "Vehicles.txt");

    for (size_t i = 0; i < size; i++)
    {

        const Vehicle& vehicle = vehs[i];

        std::cout << "Mark = " << vehicle.GetMark() << std::endl;
        std::cout << "Fuel Consumption = " << vehicle.GetFuelConsumption() << std::endl;
        std::cout << "Year of manufacture = " << vehicle.GetYearOfManufacture() << std::endl;
        std::cout << "Engine Capacity = " << vehicle.GetEngineCapacity() << std::endl;

        std::cout << std::endl;
    }

}


enum class Action {
    
    READ_MARK_LENGTH, 
    READ_MARK_CHAR,
    READ_YEAR,
    READ_ENGINE,
    READ_FUEL

};

void readFromFile(Vehicle*& vehicles, size_t& size, const std::string& fileName)
{

    std::ifstream in(fileName);

    if (!in.is_open())
        throw "Can`t open";


    size_t countOfElements = 0;
    size_t additionalCapacity = 0;

    char byte = 0;

    Action action = Action::READ_MARK_LENGTH;

    char 
        markLengthBytes[8] = { 0 },
        yearBytes[8] = { 0 },
        engineBytes[8] = { 0 },
        fuelBytes[8] = { 0 };

    char* mark = nullptr;
    size_t markLength;

    size_t markLengthCurrentIndex = 0,
           markBytesCurrentIndex = 0,
           yearBytesCurrentIndex = 0,
           engineBytesCurrentIndex = 0,
           fuelBytesCurrentIndex = 0;

    while (in.read(&byte, 1)) {


        switch (action)
        {

            case Action::READ_MARK_LENGTH:  
            {

                markLengthBytes[markLengthCurrentIndex++] = byte;

                if (markLengthCurrentIndex == 8) {

                    markLength = *((size_t*)markLengthBytes);
                    mark = new char[markLength + 1];

                    action = Action::READ_MARK_CHAR;
                }
                break;
            }
            case Action::READ_MARK_CHAR:
            {

                if (markBytesCurrentIndex == markLength) {

                    mark[markBytesCurrentIndex] = '\0';

                    action = Action::READ_YEAR;
                    break;
                }

                mark[markBytesCurrentIndex++] = byte;
                break;
            }
            case Action::READ_YEAR:
            {

                if (yearBytesCurrentIndex == 8) {
                    action = Action::READ_ENGINE;
                    break;
                }

                yearBytes[yearBytesCurrentIndex++] = byte;
                break;
            }
            case Action::READ_ENGINE:
            {
                if (engineBytesCurrentIndex == 8) {
                    action = Action::READ_FUEL;
                    break;
                }

                engineBytes[engineBytesCurrentIndex++] = byte;
                break;
            }
            case Action::READ_FUEL:
            {

                if (fuelBytesCurrentIndex != 8) {

                    fuelBytes[fuelBytesCurrentIndex++] = byte;

                    break;
                }
            }
            default:
            {

                countOfElements++;

                if (size < countOfElements) {

                    additionalCapacity = 9;

                    auto* temp = new Vehicle[countOfElements + additionalCapacity];

                    std::copy(vehicles, vehicles + size, temp);

                    if (size != 0)
                        delete[] vehicles;

                    vehicles = temp;

                    size = countOfElements + additionalCapacity;
                }
                else {
                    additionalCapacity--;
                }

                vehicles[countOfElements - 1] =
                {
                   mark,
                   *(size_t*)yearBytes,
                   *(size_t*)engineBytes,
                   *(size_t*)fuelBytes,
                };

                delete[] mark;

                action = Action::READ_MARK_LENGTH;

                markLengthCurrentIndex = 
                    markBytesCurrentIndex = 
                    yearBytesCurrentIndex = 
                    engineBytesCurrentIndex = 
                    fuelBytesCurrentIndex = 0;
                
                break;
            }
        }
    }


    if (additionalCapacity != 0) {

        size_t newSize = size - additionalCapacity;

        Vehicle* temp = new Vehicle[newSize];

        std::copy(vehicles, vehicles + newSize, temp);
         
        delete[] vehicles;

        vehicles = temp;

        size = newSize;
    }

    in.close();
}

void saveToFile(const Vehicle* vehicles, size_t size, const std::string& fileName)
{

    std::ofstream out(fileName);
    
    if(!out.is_open())
        throw "Can`t open";

    for (size_t i = 0; i < size; i++)
    {

        const Vehicle& vehicle = vehicles[i];
            
        const std::string& mark = vehicle.GetMark();


        writeBytes(out, mark.size(), 8);
        out << mark << '\0';
        writeBytes(out, vehicle.GetYearOfManufacture(), 8);
        out << '\0';
        writeBytes(out, vehicle.GetEngineCapacity(), 8);
        out << '\0';
        writeBytes(out, vehicle.GetFuelConsumption(), 8);
        out << '\0';
    }

    out.flush();
    out.close();
}

void writeBytes(std::ofstream& out, size_t value, size_t size) 
{

    auto bytes = (const char*)(&value);

    for (size_t i = 0; i < size; i++)
    {
        out << bytes[i];
    }
}