#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

const std::string& jsonInputPath = "C:\\gorkemarin\\Qoordinate\\01_Solution\\02_PoC Use Case Solution\\JSONInOut\\example\\input3.json";
const std::string& jsonOutputPath = "C:\\gorkemarin\\Qoordinate\\01_Solution\\02_PoC Use Case Solution\\JSONInOut\\example\\output3.json";

json GetJsonRequest()
{
    /* REPLACE THIS METHOD */

    return ReadJsonFile(jsonInputPath);

    /* END OF REPLACEMENT */
}

void SendJsonResponse(json response)
{
    /* REPLACE THIS METHOD */

    WriteJsonFile(jsonOutputPath, response);

    /* END OF REPLACEMENT */
}

json ReadJsonFile(const std::string& filePath)
{
    json data;
    std::ifstream file(filePath);
    if (!file.good())
    {
        std::cerr << "File doesn't exist.";
        return data;
    }

    if (!file.is_open()) {
        std::cerr << "Error: Failed to open file " << filePath << std::endl;
        // Return an empty JSON object if file cannot be opened
        return data;
    }

    data = json::parse(file);
    return data;
}

void WriteJsonFile(const std::string& filePath, json file)
{
    std::ofstream outFile(filePath);
    outFile << file;
}

void Test()
{
    json jsonIn{ GetJsonRequest() };
    int a{ jsonIn["a"] };
    int b{ jsonIn["b"] };
    std::string name = jsonIn["name"];

    json jsonOut = {
        {"name", name},
        {"sum", a + b},
        {"product", a * b}
    };

    SendJsonResponse(jsonOut);
}

int main()
{
    Test();
    return 0;
}
