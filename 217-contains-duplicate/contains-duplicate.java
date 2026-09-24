class Solution {
    public boolean containsDuplicate(int[] nums) {
        //create a hashSet to store elements from the array
        HashSet<Integer> seenNumbers = new HashSet<>();

        //Iterate through each element in the array

        for (int num : nums){
            //check if the element is already in the hashset 
            if (seenNumbers.contains(num)){
                return true; //duplicate found
            }
            //add the element to the HashSet
            seenNumbers.add(num);
        }

        return false; //no duplicated found
    }
}