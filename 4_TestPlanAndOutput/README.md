# Test Plan
| TEST ID | TEST CASE OBJECTIVE |INPUT DATA|EXPECTED OUTPUT|ACTUAL OUTPUT|STATUS|
|--|--|--|--|--|--|
| Tp1 | For Entering Name |enter name: satesh|satesh|satesh|PASS|
|Tp2|For Entering Name|enter name: satesh|satesh|-|FAIL|
|Tp3|For Entering Age|enter age: 21|21|21|PASS|
|Tp4|For Entering Age|enter age: 21|21|-|FAIL|
|Tp5|For Entering Salary|enter salary: 10000|10000|10000|PASS|
|Tp6|For Entering Salary|enter salary: 10000|10000|-|FAIL|
|Tp7|For Listing Record|satesh 21 10000|satesh 21 10000|satesh 21 10000|PASS|
|Tp8|For Listing Record|satesh 21 10000|satesh 21 10000|satesh 10000 21|FAIL|
|Tp9|For Deleting Record|satesh|satesh|satesh|PASS|
|Tp10|For Deleting Record|satesh|satesh|-|FAIL|



