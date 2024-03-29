<div class="row">
    <h1 class="text-center">Details for AS <%= @node.id %></h1>
    <h5 class="text-center">Name:<%= @node_metadata[4] %></h5>
	<h5 class="text-center">Country of registration:<%= @node_metadata[1] %></h5>
	<h5 class="text-center">Registry:<%= @node_metadata[2] %></h5>
	<h5 class="text-center">Date of registration:<%= @node_metadata[3] %></h5>
</div>

<div class="row">
  <h2 class="text-center">Metric Values</h2>
  <table class="table table-hover">
    <tr>
      <th>Metric</th>
      <th>Absolute Value</th>
      <th class="col-md-4">Normalized Value</th>
      <th>[%]</th>
    </tr>
    <% @node.metrics.each do |metric,data| %>
      <tr>
        <td><a href="/metric/<%= metric %>/"><%= data[:name] %></a></td>
        <td><%= data[:absolute].round(7) %></td>
        <td>
          <div class="metric_bar">
          <div class="progress">
            <div class="progress-bar progress-bar-<%= data[:color_class] %>" role="progressbar" aria-valuenow="<%= data[:normalized]*100 %>" aria-valuemin="0" aria-valuemax="100" style="width: 
              <%= data[:normalized]*100 %>%;">
              <span class="sr-only"><%= data[:normalized]*100 %>%</span>
            </div>
          </div>
          </div>
        </td>

        <td>
          <span class="<%= data[:color] %>">
            <%= (data[:normalized]*100).round(4) %>%
          </span>
        </td>

      </tr>
    <% end %> 
  </table>      
</div>


<div class="row">
  <h2 class="text-center">Score Values</h2>
  <table class="table table-hover">
    <tr>
      <th>Score</th>
      <th class="col-md-4">Value</th>
      <th>[%]</th>
    </tr>
    <% @node.scores.each do |score,data| %>
      <tr>
        <td><a href="/metric/<%= score %>/"><%= data[:name] %></a></td>
        <td>
          <div class="metric_bar">
          <div class="progress">
            <div class="progress-bar progress-bar-<%= data[:color_class] %>" role="progressbar" aria-valuenow="<%= data[:absolute]*100 %>" aria-valuemin="0" aria-valuemax="100" style="width: <%= data[:absolute]*100 %>%;">
              <span class="sr-only"><%= data[:absolute]*100 %>%</span>
            </div>
          </div>
          </div>
        </td>

        <td>
          <span class="text-<%= data[:color_class] %>">
            <%= (data[:absolute]*100).round(4) %>%
          </span>
        </td>

      </tr>
    <% end %> 
  </table>      
</div>

<div class="row">
  <h2 class="text-center">Node Neighborhood</h2>
  <div class="col-md-10 col-md-offset-1" id="graph">
  </div>  
</div>
  

<script type="text/javascript">
  var node_id=<%= @node.id %>;
</script>
<script src="/js/fisheye.js"></script>
<script src="/js/graph.js"></script>