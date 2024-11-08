package ForClass.Reflect;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;

public class ReflectTest {
    public static void main(String[] args) throws ClassNotFoundException {
        TestClass testClass = new TestClass();
        Constructor<?>[] constructors = testClass.getClass().getConstructors();
        for(Constructor<?> con : constructors)
        {
            System.out.println(con);
        }
        Field[] fields = testClass.getClass().getDeclaredFields();
        for(Field f : fields)
        {
            System.out.println(f);
        }
        Method[] mths = testClass.getClass().getDeclaredMethods();
        for(Method f : mths)
        {
            System.out.println(f);
        }


    }
}
