import java.util.HashMap;
import java.util.Map;

public class TwoSumThreeDataStructureDesign {
    class TwoSum {
        private Map<Integer, Integer> store;

        /** Initialize your data structure here. */
        public TwoSum() {
            this.store = new HashMap<>();
        }

        /** Add the number to an internal data structure.. */
        public void add(int number) {
            if(this.store.containsKey(number)) {
                this.store.replace(number, this.store.get(number) + 1);
            } else {
                this.store.put(number, 1);
            }
        }

        /** Find if there exists any pair of numbers which sum is equal to the value. */
        public boolean find(int value) {
            for(Map.Entry<Integer, Integer> entry : this.store.entrySet()) {
                int complement = value - entry.getKey();
                if(complement == entry.getKey()) {
                    if(entry.getValue() > 1) return true;
                } else {
                    if(this.store.containsKey(complement)) return true;
                }
            }
            return false;
        }
    }
}
