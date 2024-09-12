-- select 
--     u.product_id, 
--     ROUND(sum(units*price)/sum(units), 2) as average_price 
-- from 
--     UnitsSold u 
-- full outer join 
--     Prices p 
-- on 
--     u.purchase_date between p.start_date and p.end_date 
-- and 
--     u.product_id = p.product_id 
-- group by 
--     p.product_id;



select p.product_id, IFNULL(Round(sum(price*units)/sum(units), 2), 0) as average_price from Prices p left join UnitsSold u on u.product_id = p.product_id and u.purchase_date between p.start_date and p.end_date group by p.product_id;