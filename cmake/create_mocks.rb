require "#{ENV['CMOCK_DIR']}/lib/cmock"

raise 'Header file to mock must be specified!' unless ARGV.length >= 1

mock_out = ENV.fetch('MOCK_OUT', './build/test/mocks')
mock_prefix = ENV.fetch('MOCK_PREFIX', 'mock_')
cmock = CMock.new(:plugins => %i[ignore ignore_arg callback], :mock_prefix => mock_prefix, :mock_path => mock_out, :includes => %i[stdint.h math.h stdbool.h], :treat_externs => :include)
cmock.setup_mocks(ARGV[0])