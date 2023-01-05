// Mikołaj Bień
// pon 11:15
// 24.10.2022 / 25.10.2022
// numer albumu: 272950


#include <iostream>

struct Resault {
    int count;
    float values[2];
};


Resault solve_matrix_2x3(float m[2][3]) {
    float W = m[0][0] * m[1][1] - m[1][0] * m[0][1];
    float Wx = m[0][2] * m[1][1] - m[1][2] * m[0][1];
    float Wy = m[0][0] * m[1][2] - m[1][0] * m[0][2];
    std::cout << "W: " << W << " Wx: " << Wx << " Wy: " << Wy << std::endl;
    Resault out;
    if (W == 0) {
        if (Wx == 0 && Wy == 0) {
            out.count = -1;
            return out;
        }

        if (Wx != 0 && Wy != 0) {
            out.count = 0;
            return out;
        }
    }

    out.values[0] = Wx / W;
    out.values[1] = Wy / W;

    return out;
}

const char* remove_digits(const char* src_str) {
    int d_cnt;
    int len;
    for (len = 0, d_cnt = 0; src_str[len] != 0; len++) {
        if (src_str[len] <= '9' && src_str[len] >= '0') {
            d_cnt++;
        }
    }
    std::cout << "length: " << len << " d_count: " << d_cnt << std::endl;

    char* out = new char[len - d_cnt + 1];

    for (int i = 0, j = 0; i < len; i++) {
        if (src_str[i] <= '9' && src_str[i] >= '0') continue;

        out[j] = src_str[i];
        j++;
    }
    out[len - d_cnt] = 0;

    return out;
}

const char* delete_comments(const char* src_str) {
    int len;
    for (len = 0; src_str[len] != 0; len++);
    std::cout << "length: " << len << std::endl;

    bool delete_endl = false;
    bool delete_chunk = false;

    auto out = new char[++len];
    out[len] = 0;

    for (long long i = 0; src_str[i] != 0; i++) {
        if (!delete_endl) {
            if (src_str[i] == '/' && src_str[i + 1] == '*') delete_chunk = true;
            if (src_str[i - 2] == '*' && src_str[i - 1] == '/') delete_chunk = false;
        }

        if (!delete_chunk) {
            if (src_str[i] == '/' && src_str[i + 1] == '/') delete_endl = true;
            if (src_str[i - 1] == '\n') delete_endl = false;
        }


        if (delete_chunk || delete_endl) {
            out[i] = ' ';
        }
        else {
            out[i] = src_str[i];
            std::cout << "chuj\n";
        }
    }
    return out;
}

int main() {

    std::cout << "Mikolaj Bien\npon 11:15\n24.10.2022 / 25.10.2022\nnumer albumu: 272950\n\n";

    float test[2][3] = { {5, 3, 3},
                        {8,-6,48} };

    Resault r = solve_matrix_2x3(test);
    std::cout << "some: " << r.values[0] << ",  " << r.values[1] << std::endl;

    auto rm_str = "dasda798a7sdg09sd78";
    std::cout << remove_digits(rm_str) << std::endl;

    auto rm_com_str = "  std::cout << \"Mikolaj Bien/*npon 11:15*/n24.10.2022 / 25.10.2022\\nnumer albumu: 272950\\n\\n\";//float test[2][3] = {{5, 3, 3},{8,-6,48}};\";";
    std::cout << delete_comments(rm_com_str) << std::endl;


    return 0;
}
