using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.Start
{
    internal class TestClass2 : TestClass, Interface1
    {
        public new void Show()
        {
            Console.WriteLine("class2 show");
        }
        public void Do()
        {
            Console.WriteLine("do");
        }
    }
}
