#include<vector>
#include<random>
#include<ctime>
class RandStr {
    public:
    static std::string CrtRandStr(int rand_str_size, int option);
    private:
    static std::vector<char> ch_vec;
    static std::vector<char> upper_ch_vec;
    static std::vector<char> lower_ch_vec;
    static std::default_random_engine dre;
    static void RandOrder(std::vector<char> & vec);
};
std::string RandStr::CrtRandStr(int rand_str_size, int tag) {
    std::string ret = {};
    if (tag == 1) { //大小写
        dre.seed((unsigned)time(NULL));
        RandOrder(ch_vec);
        std::uniform_int_distribution<int> uid(0, ch_vec.size() - 1);
        for (int i = 0; i < rand_str_size; i++) {
            ret += ch_vec[uid(dre)];
        }
    }
    else if (tag == 2) { //全大写
        dre.seed((unsigned)time(NULL));
        RandOrder(upper_ch_vec);
        std::uniform_int_distribution<int> uid(0, upper_ch_vec.size() - 1);
        for (int i = 0; i < rand_str_size; i++) {
            ret += upper_ch_vec[uid(dre)];
        }
    }
    else if (tag == 3) { //首字母大写
        dre.seed((unsigned)time(NULL));
        RandOrder(lower_ch_vec);
        std::uniform_int_distribution<int> uid(0, lower_ch_vec.size() - 1);
        ret += upper_ch_vec[uid(dre)];
        for (int i = 1; i < rand_str_size; i++) {
            ret += lower_ch_vec[uid(dre)];
        }
    }
    else if (tag == 4) { //全小写
        dre.seed((unsigned)time(NULL));
        RandOrder(lower_ch_vec);
        std::uniform_int_distribution<int> uid(0, lower_ch_vec.size() - 1);
        for (int i = 0; i < rand_str_size; i++) {
            ret += lower_ch_vec[uid(dre)];
        }
    }
    return ret;
}
std::vector<char> RandStr::ch_vec = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
std::vector<char> RandStr::upper_ch_vec = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
std::vector<char> RandStr::lower_ch_vec = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
std::default_random_engine RandStr::dre;
void RandStr::RandOrder(std::vector<char> & vec) {
    dre.seed((unsigned)time(NULL));
    std::uniform_int_distribution<int> uid(0, vec.size() - 1);
    for (int i = 0; i < vec.size(); i++) {
        std::swap(vec[uid(dre)], vec[uid(dre)]);
    }
}