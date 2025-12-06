#include <iostream>
#include <vector>
using namespace std;

void printHistogram(const vector<int>& data) {
    int maxVal = 0;
    for (int x : data) maxVal = max(maxVal, x);

    for (int i = 0; i < data.size(); i++) {
        cout << i << " | ";
        int bars = (data[i] * 50) / maxVal; // Escala a 50 caracteres
        for (int j = 0; j < bars; j++) cout << '#';
        cout << " (" << data[i] << ")\n";
    }
}

int main() {
    vector<int> valores = {5, 12, 9, 20, 8, 15};
    printHistogram(valores);
}