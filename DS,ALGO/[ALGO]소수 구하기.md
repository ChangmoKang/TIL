# 소수 구하기(Sieve of Eratosthenes)

```python
def get_prime_number(n):
    is_prime = [False]*2 + [True]*(n - 1)
    for k in range(2, int(n**0.5) + 1):
        if is_prime[k]:
            is_prime[2*k::k] = [False] * ((n - k) // k)
            is_prime[2*k::k] = [False] * len(is_prime[2*k::k])
    return [x for x in range(n + 1) if is_prime[x]]
```

