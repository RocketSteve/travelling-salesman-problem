import { Component } from '@angular/core';

@Component({
    selector: 'app-graph',
    template: `
    <canvas #canvas></canvas>
  `
})
export class GraphComponent {
    @ViewChild('canvas') canvas: ElementRef<HTMLCanvasElement>;

    private ctx: CanvasRenderingContext2D;

    coordinates = [
        { x: 10, y: 20 },
        { x: 30, y: 40 },
        { x: 50, y: 60 },
        // ...
    ];

    order = [0, 1, 2, 3];

    ngAfterViewInit() {
        this.ctx = this.canvas.nativeElement.getContext('2d');
        this.draw();
    }

    private draw() {
        this.ctx.beginPath();
        this.ctx.moveTo(this.coordinates[this.order[0]].x, this.coordinates[this.order[0]].y);
        for (let i = 1; i < this.order.length; i++) {
            this.ctx.lineTo(this.coordinates[this.order[i]].x, this.coordinates[this.order[i]].y);
        }
        this.ctx.stroke();
    }
}
