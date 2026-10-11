package problems;

import lombok.Getter;
import lombok.Setter;
import org.apache.commons.collections4.CollectionUtils;

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

    public void setDfromInput(ArrayList<Double> x_star) throws Exception {
        if (CollectionUtils.isEmpty(x_star))
            throw new Exception("The provided input is empty.");

        setD(CollectionUtils.size(x_star));
    }
}
