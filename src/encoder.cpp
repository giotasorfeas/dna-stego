#include "encoder.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <ctime>
#include <random>

using namespace std;

string encode_message(const string& message){
    unordered_map<string,vector<string>> bits_to_codon =
    {
        {"00", {"TTA", "TTC", "GAA"}},
        {"01", {"TTG", "GAG", "CTG"}},
        {"10", {"CTT", "GAC", "TAT"}},
        {"11", {"CTC", "GAT", "TAG"}}
    };

    string dna = "";
    mt19937 rng(static_cast<unsigned>(time(nullptr)));

    for (char c : message) {
        string bin;
        for (int i = 7; i >= 0; --i)
            bin += ((c >> i) & 1) ? '1' : '0';

        for (size_t i = 0; i < bin.length(); i += 2) {
            string bits = bin.substr(i, 2);
            auto& options = bits_to_codon[bits];
            string codon = options[rng() % options.size()];
            dna += codon;
        }
    }

    return dna;
}