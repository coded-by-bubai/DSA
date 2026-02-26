# Brute Force Approach (O(n^2))
def is_isomorphic_bruteforce(s1, s2):
    if len(s1) != len(s2):
        return False

    n = len(s1)

    for i in range(n):
        for j in range(i):
            if s1[i] == s1[j] and s2[i] != s2[j]:
                return False
            if s1[i] != s1[j] and s2[i] == s2[j]:
                return False

    return True


# Optimal Approach (O(n))
def is_isomorphic_optimal(s1, s2):
    if len(s1) != len(s2):
        return False

    map1 = {}
    map2 = {}

    for i in range(len(s1)):
        c1 = s1[i]
        c2 = s2[i]

        if c1 in map1 and map1[c1] != c2:
            return False
        if c2 in map2 and map2[c2] != c1:
            return False

        map1[c1] = c2
        map2[c2] = c1

    return True


# Example
s1 = "aab"
s2 = "xxy"

print("Brute Force:", is_isomorphic_bruteforce(s1, s2))
print("Optimal:", is_isomorphic_optimal(s1, s2))