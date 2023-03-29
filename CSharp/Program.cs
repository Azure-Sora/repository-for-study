using System.Text;

namespace CSharp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("输入日期 XXXX XX XX");
            string date = Console.ReadLine();
            Console.WriteLine(HuiWen(date));

        }
        static string HuiWen(string date) 
        {
            string[] splitedDate = date.Split(" ");
            int year = Convert.ToInt32(splitedDate[0]);
            int month = Convert.ToInt32(splitedDate[1]);
            int day = Convert.ToInt32(splitedDate[2]);
            while(true)
            {
                StringBuilder sb = new StringBuilder();
                sb.Append(year).Append(month).Append(day);
                if (sb.ToString().Equals(sb.ToString().Reverse()))
                {
                    return sb.ToString();
                }
                if (day < 30)
                {
                    day++;
                }else if(month < 12)
                {
                    month++;
                    day = 1;
                }
                else
                {
                    year++;
                    month = 1;
                    day = 1;
                }
            }
            
        }
    }
}