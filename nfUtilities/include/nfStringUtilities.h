/************************************************************************/
/**
 * @file nfStringUtilities.h
 * @author Mara Castellanos
 * @date 27/01/24
 * @brief For all the actions involving strings that are needed.
 *
 * @bug Not bug Known.
 */
 /************************************************************************/

#pragma once
#include "nfPrerequisitesUtilities.h"

#if NF_PLATFORM == NF_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#undef min
#undef max
#endif

namespace nfEngineSDK {
  namespace stringUtils {
    using std::to_string;

    /// TODO: COMMENT THIS FUNCTION
    FORCEINLINE String
    replicateString(String origin, int count)
    {
      String r;
      for (int i = 0; i < count; ++i) {
        r += origin;
      }
      return origin;
    }

    /// TODO: COMMENT THIS FUNCTION
    FORCEINLINE Vector<String>
    splitString(const String& str, const String& delimiter)
    {
      String s = str;

      Vector<String> r = {};

      size_t pos = 0;
      String token;
      while ((pos = s.find(delimiter)) != String::npos)
      {
        token = s.substr(0, pos);
        r.push_back(token);
        s.erase(0, pos + delimiter.length());
      }
      r.push_back(s);

      return r;
    }
    
    /**
     * @brief
     * Transform a variable to a string.
     *
     * @description
     * Returns the value inside the passed variable to a string. Only for basic
     * value types.
     *
     * @param _value
     * The value to transform to a string.
     *
     * @return
     * The converted string.
     */
    template<typename T>
    FORCEINLINE String
    toString(const T& _value, int decimals = -1)
    {
      auto r = to_string(_value);

      if (decimals < 0) return r;

      auto spl = splitString(r, ".");

      if (decimals == 0) return spl[0];

      if (spl.size() == 1) return spl[0] + "." + replicateString("0", decimals);

      r = spl[0] + ".";

      String decims = spl[1];
      auto decimsCount = static_cast<int>(decims.size());
      for (int i = 0; i < decimals; ++i) {
        if (i < decimsCount) {
          r += decims[i];
        }
        else {
          r += "0";
        }
      }

      return r;
    }
    
    
    
    FORCEINLINE WString
    eeStringtoWString(const String& _value)
    {
      int32 len;
      auto slength = static_cast<int32>(_value.length() + 1);
      WString wValue;
    
    #if NF_PLATFORM == NF_PLATFORM_WIN32
      len = MultiByteToWideChar(CP_ACP, 0, _value.c_str(), slength, nullptr, 0);
    
      auto buf = new WCHAR[len];
      MultiByteToWideChar(CP_ACP, 0, _value.c_str(), slength, buf, len);
    
      wValue = buf;
    
      delete[] buf;
    #endif
    
      return wValue;
    }
    
    FORCEINLINE String
    eeWStringtoString(const WString& _wideString)
    {
      SIZE_T origsize = wcslen(_wideString.c_str()) + 1;
      SIZE_T convertedChars = 0;
    
      const SIZE_T newsize = origsize * 2;
    
      auto nstring = new char[newsize];
    
      wcstombs_s(&convertedChars, nstring, newsize, _wideString.c_str(), _TRUNCATE);
    
      String result = nstring;
    
      delete[] nstring;
      nstring = nullptr;
    
      return result;
    }
    
    FORCEINLINE String&
    localizeString(const char* stri)
    {
      static String movedString;
      movedString = stri;
      return movedString;
    }
  }
}