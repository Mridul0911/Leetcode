class Solution {
    public boolean isValid(String s) {
        HashMap<Character, Character> hm = new HashMap<Character, Character>();
hm.put('(', ')');
	hm.put('[', ']');
            hm.put('{', '}');
 
        Stack<Character> sc = new Stack<Character>();
 
	for (int i = 0; i < s.length(); i++)
        {
		char curr = s.charAt(i);
                if (hm.keySet().contains(curr)) {
			sc.push(curr);
		} else if (hm.values().contains(curr)) {
			if (!sc.empty() && hm.get(sc.peek()) == curr) {
				sc.pop();
			} else {
				return false;
			}
		}
	}
    return sc.empty();
    }
}