FILE="sample2.csv"
plot FILE using 1:2 with lines title "x";
replot FILE using 1:3 with lines title "v";
replot FILE using 1:4 with lines title "a";
replot FILE using 1:5 with lines title "remain_time";