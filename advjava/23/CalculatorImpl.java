import java.rmi.RemoteException;

public class CalculatorImpl extends java.rmi.server.UnicastRemoteObject implements Calculator {

    protected CalculatorImpl() throws RemoteException {
        super();
    }

    @Override
    public double add(double a, double b) throws RemoteException {
        System.out.println("Calculating add(" + a + ", " + b + ")");
        return a + b;
    }

    @Override
    public double subtract(double a, double b) throws RemoteException {
        System.out.println("Calculating subtract(" + a + ", " + b + ")");
        return a - b;
    }

    @Override
    public double multiply(double a, double b) throws RemoteException {
        System.out.println("Calculating multiply(" + a + ", " + b + ")");
        return a * b;
    }

    @Override
    public double divide(double a, double b) throws RemoteException {
        System.out.println("Calculating divide(" + a + ", " + b + ")");
        return a / b;
    }
}
