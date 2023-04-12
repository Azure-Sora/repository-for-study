using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.Start
{
    internal class TestClass
    {
        private int num1;
        public int Num1 { get { return num1; } set { num1 = value; } }
        public virtual void Show1()
        {
            Console.WriteLine("show of TestClass");
        }
    }
}
