package problems;

import lombok.Getter;
import lombok.Setter;

import java.util.ArrayList;

@Getter
@Setter
public abstract class Problem {

    String name;
    int d = -1;
    Double lowerBound;
    Double upperBound;

    public abstract double evaluate(ArrayList<Double> x_star) throws Exception;

    abstract int generateRandomSolution();

    public void checkBounds(Double x) throws Exception {
        if (x > getUpperBound() || x < getLowerBound())
            throw new Exception("[" + getName() + "]" + "Specimen entry is out of bounds. " +
                    "X:" + x + "; Upper bound:" + getUpperBound() + "; Lower bound:" + getLowerBound() + ".");
    }
}
