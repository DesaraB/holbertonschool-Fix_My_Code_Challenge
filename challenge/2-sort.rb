###
#
#  Sort integer arguments (ascending) 
#
###

result = []

ARGV.each do |arg|
  # skip if not integer
  next if arg !~ /^-?[0-9]+$/

  i_arg = arg.to_i
  is_inserted = false

  result.each_with_index do |val, i|
    if i_arg < val
      result.insert(i, i_arg)
      is_inserted = true
      break
    end
  end

  result << i_arg unless is_inserted
end

puts result
