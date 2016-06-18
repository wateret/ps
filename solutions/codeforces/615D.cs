using System;
using System.Linq;
using System.Collections.Generic;
using System.Numerics;

public class Program {
	const int MOD = 1000000007;

	public static int ModMult(int a, int b) {
		return (int)(((long)a*(long)b)%MOD);
	}

	public static int ModPow(int a, int n) {
		if (n == 1)
			return a;
		int t = ModPow(a, n/2);
		t = ModMult(t, t);
		if (n%2 == 1)
			t = ModMult(t, a);
		return t;
	}

	public static void Main() {
		int.Parse(Console.ReadLine());
		var tt = Console.ReadLine();
		IEnumerable<int> A = tt.Split().Select(i => int.Parse(i));
		Dictionary<int, int> D = A.GroupBy(x => x).ToDictionary(g => g.Key, g => g.Count());

		int ans = 1;
		BigInteger e = D.Values.Select(x => new BigInteger(x+1)).Aggregate(new BigInteger(1), (acc, x) => acc*x);
		foreach (var p in D) {
			int a = p.Key;
			int n = p.Value;
			BigInteger ee = e*n/2;
			ee %= MOD-1;
			int eei = (int) ee;
			ans = ModMult(ans, ModPow(a, eei));
		}
		Console.WriteLine(ans);
	}
}