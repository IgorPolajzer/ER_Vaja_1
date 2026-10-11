package misc;

import lombok.Getter;
import lombok.Setter;
import org.apache.commons.collections4.CollectionUtils;

import java.util.List;

@Getter
@Setter
public class Bound {

    Double number;
    List<Double> range;

    Bound(Double number) {
        setNumber(number);
    }

    Bound(List<Double> range) {
        setRange(range);
    }

    Object getBound() {
        if (isRange())
            return number;

        return range;
    }

    boolean isRange() {
        return CollectionUtils.isEmpty(range);
    }
}
