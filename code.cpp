#include <iostream>
#include <regex>
#include <string>

using namespace std;

struct Website {
    string URL;
    string name;
    string description;

    Website(const string& url, const string& name, const string& desc)
        : URL(url), name(name), description(desc) {}

    bool validateAndExtractProtocol(string& protocol) const {
        regex urlRegex(R"((https?)://[\w.-]+(:\d+)?(/[\w./?%&=-]*)?)");
        smatch match;

        if (regex_match(URL, match, urlRegex)) {
            protocol = match[1];
            return true;
        }
        return false;
    }

    void displayInfo() const {
        cout << "Website Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "URL: " << URL << endl;
    }
};

int main() {
    Website site("https://example.com", "Example Site", "This is an example website.");

    string protocol;
    if (site.validateAndExtractProtocol(protocol)) {
        cout << "Valid URL. Protocol: " << protocol << endl;
    } else {
        cout << "Invalid URL!" << endl;
    }

    site.displayInfo();

    return 0;
}
