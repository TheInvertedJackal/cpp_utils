#include "clip.hpp"
#include <iostream>
#include <cctype>

using namespace std;

namespace {
    template<typename T>
    struct optional{
        bool has_data = false;
        T value = 0;
    };

    template<typename E>
    optional<E> get_cli_value(string prompt){
        optional<E> ret_val;
        if(prompt == "") prompt = DEFAULT_PROMPT_SUFFIX;
        cout << prompt;
        if(cin >> ret_val.value){
            ret_val.has_data = true;
        } else {
            ret_val.has_data = false;
        }
        return ret_val;
    }

    optional<bool> parse_bool(string to_parse){
        optional<bool> ret_val;
        ret_val.has_data = true;
        for (int i = 0; i < to_parse.size() && i < 4; i++){
            to_parse[i] = tolower(to_parse[i]);
        }
        if(to_parse == "yes" || to_parse == "y"){
            ret_val.value = true;
        } else if(to_parse == "no" || to_parse == "n"){
            ret_val.value = false;
        } else {
            ret_val.has_data = false;
        }
        return ret_val;
    }

    template<typename T>
    T get_T(string prompt, string type){
        do{
            optional<T> o = get_cli_value<T>(prompt);
            if(o.has_data){
                return o.value;
            } else {
                cout << "Value was not a " << type << "!" << endl;
            }
        } while(true);
    }

    template<typename T>
    T get_T_error(string prompt, string type){
        optional<T> o = get_cli_value<double>(prompt);
        if(!o.has_data){
            string error_msg = "User did not enter a " + type + " value.";
            throw error_msg.c_str();
        }
        return o.value;
    }

    template<typename T>
    T get_T_default(string prompt, string type, T default_val){
        optional<T> o = get_cli_value<T>(prompt);
        if(!o.has_data) return default_val;
        return o.value;
    }
};

bool clip::get_boolean(string prompt){
    while(true){
        optional<string> o = get_cli_value<string>(prompt);
        if(!o.has_data){
            cout << "No value entered, please enter a value." << endl;
            continue;
        }
        optional<bool> b = parse_bool(o.value);
        if(b.has_data){
            cout << "The value of " << o.value << " is not yes or no. Please enter \"Yes\" or \"No\"" << endl;
            continue;
        }
        return b.value;
    }
}

bool clip::get_boolean_error(string prompt){
    optional<string> o = get_cli_value<string>(prompt);
    if(!o.has_data){
        throw "No value entered, please enter a value.";
    }
    optional<bool> b = parse_bool(o.value);
    if(b.has_data){
        string error_msg = "The user entered the value: " + o.value + " which was eronious.";
        throw error_msg.c_str();
    }
    return b.value;
}

bool clip::get_boolean_default(string prompt, bool default_val){
    optional<string> o = get_cli_value<string>(prompt);
    if(!o.has_data){
        return default_val;
    }
    optional<bool> b = parse_bool(o.value);
    if(b.has_data){
        return default_val;
    }
    return b.value;
}

double clip::get_double(string prompt){
    return get_T<double>(prompt, "double");
}

double clip::get_double_error(string prompt){
    return get_T_error<double>(prompt, "double");
}

double clip::get_double_default(string prompt, double default_val){
    return get_T_default<double>(prompt, "double", default_val);
}

int clip::get_int(string prompt){
    return get_T<int>(prompt, "integer");
}

int clip::get_int_error(string prompt){
    return get_T_error<int>(prompt, "integer");
}

int clip::get_int_default(string prompt, int default_val){
    return get_T_default<int>(prompt, "integer", default_val);
}

string clip::get_string_raw(string prompt){
    return get_T<string>(prompt, "string");
}

string clip::get_string(string prompt){
    do{
        string v = clip::get_string_raw(prompt);
        if(v == ""){
            cout << "Please enter a non-empty string." << endl;
        } else {
            return v;
        }
    } while(true);
}

string clip::get_string_error(string prompt){
    string v = clip::get_string_raw(prompt);
    if(v == "") throw "The User entered an empty string.";
    return v;
}

string clip::get_string_default(string prompt, string default_val){
    string v = clip::get_string_raw(prompt);
    if(v == "") return default_val;
    return v;
}