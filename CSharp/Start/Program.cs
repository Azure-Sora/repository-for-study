using System.Text;

namespace CSharp.Start
{
    internal class Program
    {
        static void Main(string[] args)
        {
            TestClass2 class1 = new TestClass2();
            TestClass2 class2 = new TestClass2();
            TestClass2 class3 = new TestClass2();
            showAll(class1, class2, class3);
        }
        static void showAll(params TestClass2[] classes)
        {
            foreach (TestClass2 testClass in classes)
            {
                testClass.Num1 = 5;
                testClass.Show1();
                testClass.Do();
            }
        }
    }
}