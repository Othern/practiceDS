import numpy as np

def LPS(s):
    lps = np.zeros(len(s), dtype=int)
    j = 0  # length of the previous longest prefix suffix
    for i in range(1, len(s)):
        while j > 0 and s[i] != s[j]:
            j = lps[j - 1]  # fall back to the previous LPS value
        if s[i] == s[j]:
            j += 1
            lps[i] = j
        else:
            lps[i] = 0
    return lps

def KMP(s1, s2):
    lps = LPS(s1)
    k = 0  # index for s1
    for i in range(len(s2)):  # index for s2
        while k > 0 and s1[k] != s2[i]:
            k = lps[k - 1]  # fall back in the pattern
        if s1[k] == s2[i]:
            k += 1
        if k == len(s1):  # match found
            print("Valid shift at index", i - len(s1) + 1)
            k = lps[k - 1]  # reset k using LPS

# Example usage
s1 = "abcfgkabc"
s2 = "avefgdckblcdddabcfgkabc"
KMP(s1, s2)