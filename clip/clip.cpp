#include "clip.hpp"
#include <iostream>

using namespace clip;
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

bool get_boolean(string prompt){
    bool has_answer = false;
    while(has_answer){
        optional<string> o = get_cli_value<string>(prompt);
        has_answer = o.has_data;
        if(!has_answer){
            cout << "No string entered, please enter a value." << endl;
            continue;
        }
    }
    return false;
}

bool get_boolean_error(string prompt){
    optional<string> o = get_cli_value<string>(prompt);
    return false;
}

bool get_boolean_default(string prompt, bool default_val){
    optional<string> o = get_cli_value<string>(prompt);
    //if(o.has_data) return o.value;
    return false;
}

double get_double(string prompt){
    return get_T<double>(prompt, "double");
}

double get_double_error(string prompt){
    return get_T_error<double>(prompt, "double");
}

double get_double_default(string prompt, double default_val){
    return get_T_default<double>(prompt, "double", default_val);
}

int get_int(string prompt){
    return get_T<int>(prompt, "integer");
}

int get_int_error(string prompt){
    return get_T_error<int>(prompt, "integer");
}

int get_int_default(string prompt, int default_val){
    return get_T_default<int>(prompt, "integer", default_val);
}

int get_string(string prompt){
    get_T<string>(prompt, "string");
}

