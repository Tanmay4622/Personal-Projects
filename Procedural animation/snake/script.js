const container = document.getElementById('box');
const point1 = document.getElementById('point1');
const point2 = document.getElementById('point2');
const point3 = document.getElementById('point3');
const point4 = document.getElementById('point4');
const point5 = document.getElementById('point5');
const point6 = document.getElementById('point6');
const point7 = document.getElementById('point7');
const point8 = document.getElementById('point8');
const point9 = document.getElementById('point9');
const point10 = document.getElementById('point10');
const point11 = document.getElementById('point11');
const point12 = document.getElementById('point12');
const point13 = document.getElementById('point13');
const point14 = document.getElementById('point14');
const point15 = document.getElementById('point15');
const body = document.getElementById('body');

let lastCursorPos = { x: 0, y: 0 };
let points = [
  { x: 0, y: 0, el: point1 },
  { x: 0, y: 0, el: point2 },
  { x: 0, y: 0, el: point3 },
  { x: 0, y: 0, el: point4 },
  { x: 0, y: 0, el: point5 },
  { x: 0, y: 0, el: point6 },
  { x: 0, y: 0, el: point7 },
  { x: 0, y: 0, el: point8 },
  { x: 0, y: 0, el: point9 },
  { x: 0, y: 0, el: point10 },
  { x: 0, y: 0, el: point11 },
  { x: 0, y: 0, el: point12 },
  { x: 0, y: 0, el: point13 },
  { x: 0, y: 0, el: point14 },
  { x: 0, y: 0, el: point15 }
];
const chainGap = 30;

container.addEventListener('mousemove', function(e) {
  const rect = container.getBoundingClientRect();
  lastCursorPos.x = e.clientX - rect.left - point1.offsetWidth / 2;
  lastCursorPos.y = e.clientY - rect.top - point1.offsetHeight / 2;
});

function followRigidChain() {
  // First point follows cursor
  points[0].x += (lastCursorPos.x - points[0].x) * 0.08;
  points[0].y += (lastCursorPos.y - points[0].y) * 0.08;
  points[0].el.style.left = points[0].x + 'px';
  points[0].el.style.top = points[0].y + 'px';

  // Each subsequent point maintains a rigid gap from the previous
  for (let i = 1; i < points.length; i++) {
    let dx = points[i].x - points[i-1].x;
    let dy = points[i].y - points[i-1].y;
    let dist = Math.hypot(dx, dy);
    if (dist !== chainGap) {
      let angle = Math.atan2(dy, dx);
      points[i].x = points[i-1].x + Math.cos(angle) * chainGap;
      points[i].y = points[i-1].y + Math.sin(angle) * chainGap;
    }
    points[i].el.style.left = points[i].x + 'px';
    points[i].el.style.top = points[i].y + 'px';
  }
  requestAnimationFrame(followRigidChain);
}

followRigidChain();

