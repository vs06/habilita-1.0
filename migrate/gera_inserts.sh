#!/bin/bash
j=0
tam=$(wc -l answers)
tam=$(echo $tam| awk '{print $1}')

while read line
do
        perg=$line
        first=$((j*6))
        first=$((tam-first))
        resps=$(cat answers | tail -$first | head -6)
        ra=$(echo $resps | cut -d# -f1)
        rb=$(echo $resps | cut -d# -f2)
        rc=$(echo $resps | cut -d# -f3)
        rd=$(echo $resps | cut -d# -f4)
        re=$(echo $resps | cut -d# -f5)
        r=$(echo $resps | cut -d# -f6)
        echo -e "INSERT INTO question VALUES ("$j",'"$perg"','"$ra"','"$rb"','"$rc"','"$rc"','"$rd"','"$re"','"$r"');\n"
        j=$((j+1))
done < questions

#j=0;
#next=1;
#while read i
#do
#       j=$((j+1))
#       temp=$((j-6))
#       if [[ next -eq temp  ]]
#       then
#               pergunta=$i
#               echo -e $pergunta
#       fi
#       alta=$i
#       altb=$i
#       altc=$i
#       altd=$i
#
#       test=$(($j % 6))
#       if [[ test -eq 0 ]]
#       then
#               alte=$i
#               echo -e $alte
#       fi
#
#       test=$(($j % 7))
#       if [[ test -eq 0 ]]
#       then
#               resp=$i
#               echo -e $resp
#               next=$((next+1))
#       fi
#done < $1
