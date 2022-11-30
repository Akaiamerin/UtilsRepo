import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
public class RandStr {
    private static final ArrayList<Character> CH_ARR_LIST = new ArrayList<>(Arrays.asList('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'));
    private static final ArrayList<Character> UPPER_CH_ARR_LIST = new ArrayList<>(Arrays.asList('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'));
    private static final ArrayList<Character> LOWER_CH_ARR_LIST = new ArrayList<>(Arrays.asList('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'));
    private static final SecureRandom secRand = new SecureRandom();
    private static void randOrder(ArrayList<Character> arrList) {
        for (int i = 0; i < arrList.size(); i++) {
            Collections.swap(arrList, secRand.nextInt(arrList.size()), secRand.nextInt(arrList.size()));
        }
    }
    public static StringBuilder crtRandStr(int randStrSize, int tag) {
        StringBuilder ret = new StringBuilder();
        if (tag == 1) { //大小写
            randOrder(CH_ARR_LIST);
            for (int i = 0; i < randStrSize; i++) {
                ret.append(CH_ARR_LIST.get(secRand.nextInt(CH_ARR_LIST.size())));
            }
        }
        else if (tag == 2) { //全大写
            randOrder(UPPER_CH_ARR_LIST);
            for (int i = 0; i < randStrSize; i++) {
                ret.append(UPPER_CH_ARR_LIST.get(secRand.nextInt(UPPER_CH_ARR_LIST.size())));
            }
        }
        else if (tag == 3) { //首字母大写
            randOrder(LOWER_CH_ARR_LIST);
            ret.append(UPPER_CH_ARR_LIST.get(secRand.nextInt(UPPER_CH_ARR_LIST.size())));
            for (int i = 1; i < randStrSize; i++) {
                ret.append(LOWER_CH_ARR_LIST.get(secRand.nextInt(LOWER_CH_ARR_LIST.size())));
            }
        }
        else if (tag == 4) { //全小写
            randOrder(LOWER_CH_ARR_LIST);
            for (int i = 1; i < randStrSize; i++) {
                ret.append(LOWER_CH_ARR_LIST.get(secRand.nextInt(LOWER_CH_ARR_LIST.size())));
            }
        }
        return ret;
    }
}