use std::io::*;
use std::str::FromStr;

fn read<T: FromStr>() -> T {
    let stdin = stdin();
    let stdin = stdin.lock();
    let token: String = stdin
        .bytes()
        .map(|c| c.expect("failed to read char") as char) 
        .skip_while(|c| c.is_whitespace())
        .take_while(|c| !c.is_whitespace())
        .collect();
    token.parse().ok().expect("failed to parse token")
}

fn main () {
    let n = read();
    let mut p = vec![0;0];

    for i in 0..n {
	p.push(read());
    }
    
    let mut diffs = vec![0; 0];

    for i in 1..n {
	for x in 0..=100 {
	    if p[0] + x > p[i] {
		diffs.push(x);
		break;
	    }
	}
    }

    let mut max = 0;
    
    for i in 0..diffs.len() {
	if max < diffs[i] {
	    max = diffs[i];
	}
    }

    println!("{}", max);
}
