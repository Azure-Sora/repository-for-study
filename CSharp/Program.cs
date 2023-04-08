using System.Text;

namespace CSharp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] ints = { 1, 2, 3, 4, 5 };
            foreach (var a in ints)
            {
                Console.WriteLine(a);
            }

        }
    }
}