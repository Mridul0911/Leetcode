select 
eu.product_name as product_name, e.year as year,e.price as price
from Sales e left join Product eu on e.product_id = eu.product_id