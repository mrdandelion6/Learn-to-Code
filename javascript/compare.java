// this is to compare syntax of java and javascript as i code

import java.util.ArrayList;
import java.util.List;

public class compare {
    public static void main(String[] args) {
        for (int x = 5; x <=10;) {
            System.out.println(x);
             x++;
        }
        // System.out.println(x); cant access x outside of loop

        ArrayList<String> arrayList = new ArrayList<>();
        List<String> list = new ArrayList<>(); // ArrayList implements List interface

        String[] aStrings = new String[5];
        // can also make standard arrays like this:
        String[] aStrings2 = {"yo", "ya"};
    }

}
