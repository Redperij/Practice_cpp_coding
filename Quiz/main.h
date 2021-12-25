#pragma once
#ifndef _main_h
#define _main_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <memory>
#include <exception>
#include <stdexcept>

#include "json.hpp"

using json = nlohmann::json;

#define DEBUG 1 //Use to see debug prints.
#define RAPID_INPUT 1 //Enables accepting input with simple 'enter' rather than writing 'y'.

#endif