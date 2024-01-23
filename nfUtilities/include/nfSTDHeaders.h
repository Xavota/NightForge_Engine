/************************************************************************/
/**
 * @file nfSTDHeathers.h
 * @author Diego Castellanos
 * @date 22/01/24
 * @brief All the includes and wraps for the std library.
 *
 * @bug Not bug Known.
 */
/************************************************************************/

#pragma once

#include <vector>
#include <map>
#include <memory>
#include <cmath>
#include <functional>

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <chrono>

#include <filesystem>


#include <cctype>
#include <thread>
#include <cassert>

#include <mutex>
#include <memory>
#include <condition_variable>

//#include <stringapiset.h>

#include "nfPlatformTypes.h"

namespace nfEngineSDK
{
using std::vector;
using std::map;
using std::pair;
using std::shared_ptr;
using std::weak_ptr;
using std::enable_shared_from_this;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::wstring;
using std::forward;
using std::stringstream;
using std::function;

/*
 * @brief Basic const char*
 */
using String = string;
/*
 * @brief Wide const char*
 */
using WString = wstring;

/*
 * @brief Dynamic Array of objects
 */
template<typename T, typename A = std::allocator<T>>
using Vector = vector<T, A>;
/*
 * @brief Library with a key and value
 */
template<typename T, typename U>
using Map = map<T, U>;
/*
 * @brief Single variable with a key and a value
 */
template<typename T, typename U>
using Pair = pair<T, U>;

/*
 * @brief Shared pointer
 */
template<typename T>
using SPtr = shared_ptr<T>;
/*
 * @brief Weak pointer
 */
template<typename T>
using WPtr = weak_ptr<T>;
/*
 * @brief For parenting on smart pointer use. Enable getting a SPtr from 'this'.
 */
template<typename T>
using EnableSPtrFromThis = enable_shared_from_this<T>;

/*
 * @brief General file stream
 */
using FStream = fstream;
/*
 * @brief Input file stream
 */
using IFStream = ifstream;
/*
 * @brief Output file stream
 */
using OFStream = ofstream;
/*
 * @brief String stream
 */
using SStream = stringstream;

/*
 * @brief Function template type
 */
template<class FType>
using Function = function<FType>;






}