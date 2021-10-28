// Exercise 2A

#include <iostream>
#include <fstream>
#include <string>

#define LOCATION "location"
#define TEMPERATURE "temp_c"

using namespace std;

string find_field(const string &xml, string tag_name);

int main() {
	string page, line, location, temperature;
	ifstream inputFile("weather.xml");
	
	while (getline (inputFile, line)) {
 	    page.append(line);
 	    line.erase();
	}
	// Now page is a string that contains the whole xml page
	
	// Here you need to write something that finds and 
	// extracts location and temperature from the XML
	// data in the string page and stores them in 
	// the strings location and temperature respectively

	location = find_field(page, LOCATION);
	temperature = find_field(page, TEMPERATURE);
	
	cout << "Location: " << location << endl;
	cout << "Temperature: " << temperature << endl; 
	
}


string find_field(const string &xml, string tag_name)
{
	// construct start and end tags from the tag name 
	// add angle brackets to both tags and also slash to end tag
	// then search for tags 
	// if both are found then return the substring between the tags

	string start_tag = "<" + tag_name + ">";
	string end_tag = "</" + tag_name + ">";
	string result = "not found";
	size_t start = 0;
	size_t end = 0;
	start = xml.find(start_tag);
	end = xml.find(end_tag);
	if (start != string::npos && end != string::npos) {
		//Setting correct start and end indexes.
		start += start_tag.size();
		end--;
		//If there is at least one character between them -> take this string as result.
		if (start <= end) {
			result = xml.substr(start, end - start + 1);
		}
	}
	
	return result; // return this if tag is not found
}
