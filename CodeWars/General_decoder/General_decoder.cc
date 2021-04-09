#include <string>
using namespace std;
struct Decoder{
    static std::string decode(const std::string& p_what){
        string w, out, test;
        string alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?!- ";
        int max = p_what.length();
        w.resize(max);
        out.resize(max);
        test.resize(max);
        for (int i = 0; i < 68; i++){
            for (int y = 0; y < max; y++)
                w[y] = alph[i];
            test = Encoder::encode(w);
            for (int y = 0; y < max; y++){
                if (p_what[y] == test[y])
                    out[y] = w[y];
            }
        }
        return out;
    }
};