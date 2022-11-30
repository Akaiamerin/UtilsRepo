import java.time.LocalDate;
import java.time.LocalTime;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
public class CurDateTime {
    public static String getCurDate(int tag) {
        String ret = null;
        if (tag == 1) {
            ret = LocalDate.now().format(DateTimeFormatter.ofPattern("yyyyMMdd"));
        }
        else if (tag == 2) {
            ret = LocalDate.now().format(DateTimeFormatter.ofPattern("yyyy/MM/dd"));
        }
        else if (tag == 3) {
            ret = LocalDate.now().format(DateTimeFormatter.ofPattern("yyyy年MM月dd日"));
        }
        return ret;
    }
    public static String getCurTime(int tag) {
        String ret = null;
        if (tag == 1) {
            ret = LocalTime.now().format(DateTimeFormatter.ofPattern("HHmmss"));
        }
        else if (tag == 2) {
            ret = LocalTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss"));
        }
        else if (tag == 3) {
            ret = LocalTime.now().format(DateTimeFormatter.ofPattern("HH时mm分ss秒"));
        }
        return ret;
    }
    public static String getCurDateTime(int tag) {
        String ret = null;
        if (tag == 1) {
            ret = LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss"));
        }
        else if (tag == 2) {
            ret = LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss"));
        }
        else if (tag == 3) {
            ret = LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy年MM月dd日HH时mm分ss秒"));
        }
        return ret;
    }
}