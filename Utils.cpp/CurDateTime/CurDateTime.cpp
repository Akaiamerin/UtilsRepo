#include<chrono>
#include<iomanip>
class CurDateTime {
    public:
    static std::string GetCurDate(int tag) {
        std::string ret = {};
        if (tag == 1) {
            time_t cur_date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::stringstream ss;
            ss << std::put_time(std::localtime(&cur_date), (std::string{"%Y%m%d"}).c_str());
            ret = ss.str();
        }
        else if (tag == 2) {
            time_t cur_date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::stringstream ss;
            ss << std::put_time(std::localtime(&cur_date), (std::string{"%Y/%m/%d"}).c_str());
            ret = ss.str();
        }
        else if (tag == 3) {
            time_t cur_date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::stringstream ss;
            ss << std::put_time(std::localtime(&cur_date), (std::string{"%Y年%m月%d日"}).c_str());
            ret = ss.str();
        }
        return ret;
    }
    static std::string GetCurTime(int tag) {
        std::string ret = {};
        if (tag == 1) {
            time_t cur_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::stringstream ss;
            ss << std::put_time(std::localtime(&cur_time), (std::string{"%H%M%S"}).c_str());
            ret = ss.str();
        }
        else if (tag == 2) {
            time_t cur_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::stringstream ss;
            ss << std::put_time(std::localtime(&cur_time), (std::string{"%H/%M/%S"}).c_str());
            ret = ss.str();
        }
        else if (tag == 3) {
            time_t cur_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::stringstream ss;
            ss << std::put_time(std::localtime(&cur_time), (std::string{"%H时%M分%S秒"}).c_str());
            ret = ss.str();
        }
        return ret;
    }
    static std::string GetCurDateTime(int tag) {
        std::string ret = {};
        if (tag == 1) {
            time_t cur_date_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::stringstream ss;
            ss << std::put_time(std::localtime(&cur_date_time), (std::string{"%Y%m%d%H%M%S"}).c_str());
            ret = ss.str();
        }
        else if (tag == 2) {
            time_t cur_date_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::stringstream ss;
            ss << std::put_time(std::localtime(&cur_date_time), (std::string{"%Y/%m/%d %H:%M:%S"}).c_str());
            ret = ss.str();
        }
        else if (tag == 3) {
            time_t cur_date_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::stringstream ss;
            ss << std::put_time(std::localtime(&cur_date_time), (std::string{"%Y年%m月%d日%H时%M分%S秒"}).c_str());
            ret = ss.str();
        }
        return ret;
    }
    private:
    static time_t cur_time;
};
time_t CurDateTime::cur_time = time(NULL);