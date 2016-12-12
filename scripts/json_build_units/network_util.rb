require 'net/http'

# Interface for the UVa and Codeforces requests
module NetworkUtil
	class Uva
		@@initialized = false
		def self.initialize
			unless @@initialized
				print 'Fetching data from uHunt...'
				uri = URI.parse('http://uhunt.onlinejudge.org/api/p')
				request = Net::HTTP::Get.new(uri.to_s)
				response = Net::HTTP::start(uri.hostname, uri.port) {|http| http.request(request)}
				@@problems = JSON.parse(response.body).map{|problem| [problem[1], [problem[0], problem[2]]]}.to_h # {..., pnum: [pid, name], ...}
				print " Done ! #{@@problems.size} problems detected !\n"
				@@initialized = true
			end
		end

		def self.get_problem_url(pnum)
			if @@problems.has_key? pnum
				return "[UVa #{pnum} - #{@@problems[pnum][1]}](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=#{@@problems[pnum][0]}&category=)"
			else
				return "Unkown problem (UVa #{pnum})"
			end
		end
	end

	class Codeforces
		@@initialized = false
		def self.initialize
			unless @@initialized
				print 'Fetching data from Codeforces...'
				uri = URI.parse('http://codeforces.com/api/problemset.problems')
				request = Net::HTTP::Get.new(uri.to_s)
				response = Net::HTTP::start(uri.hostname,uri.port) {|http| http.request(request)}
				@@problems = JSON.parse(response.body)['result']['problems'].map{|p| [p["contestId"].to_s + p["index"].to_s, [p["contestId"], p["index"],p["name"]]]}.to_h # {..., handle: [contest id, index, name], ...}
				print " Done ! #{@@problems.size} problems detected !\n"
				@@initialized = false
			end
		end

		def self.get_problem_url(handle)
			if @@problems.has_key? handle
				return "[Codeforces #{handle} - #{@@problems[handle][2]}](http://codeforces.com/problemset/problem/#{@@problems[handle][0]}/#{@@problems[handle][1]})"
			else
				return "Unkown problem (Codeforces #{handle})"
			end
		end
	end
end
