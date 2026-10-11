package problems;

import java.util.ArrayList;

public class Levy extends Problem {

    public Levy() {
        setName("Levy");
        setLowerBound(-10.0);
        setUpperBound(10.0);
    }

    @Override
    public double evaluate(ArrayList<Double> x_star) throws Exception {
        setDfromInput(x_star);

        var omegaList = new ArrayList<Double>();
        var secondTerm = 0.0;

        // Init omegas.
        for(var i = 0; i < getD(); i++) {
            var x = x_star.get(i);
            checkBounds(x);

            var omega = 1 + (x - 1) / 4;
            omegaList.add(omega);
        }

        // Second Term.
        for(var i = 0; i < getD() - 1; i++) {
            var x = x_star.get(i);
            var omega = omegaList.get(i);
            var omegaD = omegaList.getLast();
            checkBounds(x);

            secondTerm += Math.pow((omega - 1), 2) * (1 + 10 * Math.pow(Math.sin(Math.PI * omega + 1), 2));
            secondTerm += Math.pow((omegaD - 1), 2) * (1 + Math.pow(Math.sin(2 * Math.PI * omegaD), 2));
        }

        var firstTerm = Math.pow(Math.sin(Math.PI * omegaList.getFirst()), 2);

        return firstTerm + secondTerm;
    }

    @Override
    int generateRandomSolution() {
        return 0;
    }
}
