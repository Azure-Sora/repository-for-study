package ForClass.ArrayList;

public class AccessArrayWithForLoop {
        public static void main(String[] args) {
            String[] months = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "July", "Aug", "Sep", "Oct", "Nov", "Dec"};
            int[] sizes = {31,28,31,30,31,30,31,31,30,31,30,31};
            for(int i = 0; i <= months.length; i++ ) {
                System.out.println(months[i] + " has " + sizes[i] + " days.");
            }

    }
}
