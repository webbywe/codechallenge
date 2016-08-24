<ul id="results">
<?php foreach($results as $row): ?>
  <li>
    <h2><?php print _challenge_translate_operation($row['operation']); ?></h2>

    <div class="content">
      <h3>Arguments</h3>
      <ul class="arguments">
        <?php foreach($row['arguments'] as $argument): ?>
          <li><?php print $argument; ?></li>
        <?php endforeach; ?>
      </ul>

      <h3>Solution</h3>
      <ul class="solution">
        <?php print $row['solution']; ?>
      </ul>
    </div>
  </li>
<?php endforeach; ?>
<ul>
