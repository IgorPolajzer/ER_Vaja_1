package problems;

import java.util.ArrayList;

public class Trid extends Problem {

    public Trid() {
        setName("Trid");
    }

    @Override
    public void setD(int d) {
        super.setD(d);
        setLowerBound((double) -(d * d));
        setUpperBound((double) (d * d));
    }

    @Override
    public double evaluate(ArrayList<Double> x_star) {
        return 0;
    }

    @Override
    int generateRandomSolution() {
        return 0;
    }
}
