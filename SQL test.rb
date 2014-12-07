#!/usr/bin/ruby

require 'mysql'
require 'mysql2'


begin
      node = 1
#      con = Mysql.new '141.20.102.131', 'root', 'c1edd62dad','AS'
      con = Mysql.new '141.20.105.237', 'researcher', 'r3s3@rch','AS'
#       con = Mysql.new '141.20.102.131', 'iwi', 'c1edd62dad','AS'
      query = "SELECT * FROM AS.AS WHERE AS.AS.id=#{node}"
      puts query
      rs = con.query(query)
      n_rows = rs.num_rows
      puts "There are #{n_rows} rows in the result set"
      if rs.num_rows > 0 
        res1 = rs.fetch_row  
      else
        res1 = [0,0,0,0]
      end
                
#       test = rs.fetch_row.to_s
#       puts rs.fetch_row.join("\s")
#       puts res1
#       puts res1
#        puts res1[3]
       
  rescue Mysql::Error => e
      puts e.errno
      puts e.error
      
  ensure
      con.close if con
  end