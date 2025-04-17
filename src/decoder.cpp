#include "decoder.h"
#include <unordered_map>
#include <string>

using namespace std;

string decode_dna(const string& dna){
    unordered_map<string,string> codon_to_bits =
    {
        {"TTA", "00"}, {"TTC", "00"}, {"GAA", "00"},
        {"TTG", "01"}, {"GAG", "01"}, {"CTG", "01"},
        {"CTT", "10"}, {"GAC", "10"}, {"TAT", "10"},
        {"CTC", "11"}, {"GAT", "11"}, {"TAG", "11"}
    };

    string bits = "";
    string message = "";

    for (size_t i = 0; i < dna.length(); i += 3){
        string codon = dna.substr(i,3);
        if (codon_to_bits.count(codon) == 0) continue;
        bits += codon_to_bits[codon];
        if (bits.length() == 8) {
            char ch = static_cast<char>(std::stoi(bits, nullptr, 2));
            message += ch;
            bits.clear();
        }
    }

    return message;
}