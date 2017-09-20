#include "Java.h"
#include "Pascal.h"

using namespace std;

const string FLAGS = "[-ix]";
const string USAGE =
    "Usage: make execute|compile " + FLAGS + " <source file path>";

/**
 * The main method.
 * @param args command-line arguments: "compile" or "execute" followed by
 *             optional flags followed by the source file path.
 */
int main(int argc, char *args[])
{
    string language = "";
    cout << "What language?(Java, Pascal)" << endl;
    cin >> language;

    while((language != "Java" && language != "Pascal")) {
        cout << "Wrong Language(Java, Pascal)" << endl;
        cin >> language;
    }

    try {
        // Operation.
        string operation = args[1];
        if ((operation != "compile") && (operation != "execute"))
        {
            throw USAGE;
        }

        // Flags.
        string flags = "";
        int i = 1;
        while ((++i < argc) && (args[i][0] == '-'))
        {
            flags += string(args[i]).substr(1);
        }

        // Source path.
        if (i < argc) {
            string path = args[i];
            if (language == "Java") Java(operation, path, flags);
            else Pascal(operation, path, flags);
        }
        else {
            throw string("Missing source file.");
        }
    }
    catch (string& msg) {
        cout << "***** ERROR: " << msg << endl;
    }

    return 0;
}

