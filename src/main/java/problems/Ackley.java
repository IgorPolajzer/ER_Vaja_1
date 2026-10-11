package problems;

import java.util.ArrayList;

public class Ackley extends Problem {

    public Ackley() {
        setName("Ackley");
        setLowerBound(-32.768);
        setUpperBound(32.768);
    }

    @Override
    public double evaluate(ArrayList<Double> x_star) throws Exception {
        setDfromInput(x_star);

        var a = 20;
        var b = 0.2;
        var c = 2 * Math.PI;
        var d = getD();

        // Iteration operations.
        var firstSum = 0.0;
        var secondSum = 0.0;

        for(var i = 0; i < getD(); i++) {
            var x = x_star.get(i);

            checkBounds(x);

            firstSum += x * x;
            secondSum += Math.cos(c * x);
        }

        // First Term.
        var k = (1.0 / d) * firstSum;
        var root = Math.pow(- b, 1.0 / k);
        var firstTerm = - a * Math.exp(root);

        // Second root.
        var secondTerm = Math.exp((1.0 / d) * secondSum);

        return firstTerm - secondTerm + a + Math.exp(1);
    }

    @Override
    int generateRandomSolution() {
        return 0;
    }
}
